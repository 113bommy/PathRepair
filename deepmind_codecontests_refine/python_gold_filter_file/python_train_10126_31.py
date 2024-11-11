t = int(input())
answer = []
for a in range(t):
    n = int(input())
    count = [0 for i in range(26)]
    for j in range(n):
        line = list(input())
        for k in line:
            count[ord(k)-97] += 1
        ans = True
    for k in count:
        if(k%n != 0):
            ans = False
            break
    if(ans):
        answer.append("YES")
    else:
        answer.append("NO")
for b in answer:
    print(b)
