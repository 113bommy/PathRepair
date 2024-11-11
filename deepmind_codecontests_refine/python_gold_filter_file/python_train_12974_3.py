n, t = input().split()
l=list(map(int,input().split()))

x=86400
c=0
for i in range(int(n)):
    c+=x-l[i]
    if c>=int(t):
        print(i+1)
        break
    