import collections
for _ in range(int(input())):
    n=int(input())
    s=1
    i=3
    c=1
    while(s<n):
        s+=i
        i+=2
        c+=1
    print(c)