def f():
    n = int(input())
    word01 = dict()
    word10 = dict()
    have00 = 0
    have11 = 0
    for i in range(n):
        w = input()
        tag = w[0]+w[-1]
        if tag == '01':
            word01[w] = i
        elif tag == '10':
            word10[w] = i
        elif tag == '11':
            have11 = 1
        elif tag == '00':
            have00 = 1
    l01 = len(word01)
    l10 = len(word10)
    if l01==0 and l10 == 0:
        if have11 and have00:
            print(-1)
            return
    if l01 < l10:
        word10, word01 = word01, word10
        l10, l01 = l01, l10
    # 01 is more than 10
    if l01 - l10 < 2:
        print(0)
        print()
        return
    count = (l01 - l10)//2
    changeIndex = []
    for w in word01:
        if count <= 0:
            break
        if w[::-1] in word10:
            continue
        changeIndex.append(word01[w])
        count -= 1
    print(len(changeIndex))
    print(' '.join(str(s+1)for s in changeIndex))

t = int(input())
for i in range(t):
    f()