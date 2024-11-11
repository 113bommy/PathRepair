n = int(input())
s = input()
if s.count('(')!=s.count(')'):
    print(-1)
elif n%2!=0:
    print(-1)
else:
    prefix = [0]
    for i in range(n):
        if s[i] == '(':
            prefix.append(prefix[-1]+1)
        else:
            prefix.append(prefix[-1]-1)
    i = 0
    n = n+1
    down = 0
    #print(prefix)
    while i<n:
        if prefix[i]<0:
            down+=2
            i = i + 1
            while i <n and prefix[i]!=0:
                i += 1
                down+=1
            #print(down)
        else:
            i += 1
    print(down)      