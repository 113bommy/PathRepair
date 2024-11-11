n= int(input())
lst=[(a,b) for a in ['S','H','C','D'] for b in range(1,14)]
for i in range(n):
    a,b =input().split()
    lst.remove((a,int(b)))
for (a,b) in lst:
    print(a,b)
