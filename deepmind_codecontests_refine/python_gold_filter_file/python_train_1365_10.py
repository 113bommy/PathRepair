n,d = map(int,input().split())
s = list(map(int,input().split()))
p = list(map(int,input().split()))
maxPoints = s[d-1]+p[0]
pos = n-1
points = 1
count = 0
while (pos>=0 and points<n):
    if (pos == d-1):
        pos -= 1
    else:
        if (s[pos]+p[points]<=maxPoints):
            count += 1
            points += 1
            pos -= 1
        else:
            points += 1
print(n-count)
