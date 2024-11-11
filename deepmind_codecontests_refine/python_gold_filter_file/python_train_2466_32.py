n=int(input())
a=list(map(int,input().split()))
a.sort()
if len(a)%2!=0:
        print(a[len(a)//2])
else:
        print (a[(len(a)//2)-1])
