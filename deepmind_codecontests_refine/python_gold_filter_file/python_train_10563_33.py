prof , lang = map(int,input().strip().split())
arr = dict()
ans = []
for i in range(lang):
    s = input().split()
    arr[s[0]] = s[1]
speech = input().split()
for i in speech:
    if len(i) > len(arr[i]): ans.append(arr[i])
    else:  ans.append(i)
print(' '.join(ans))