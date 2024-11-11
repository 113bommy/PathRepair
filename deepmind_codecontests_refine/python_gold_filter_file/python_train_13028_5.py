n=int(input())
a=input().split()
if(a.count("1")==0 or a.count("2")==0):
    print(*a)
else:
    a.remove("2")
    a.remove("1")
    a.sort(reverse=True)
    print("2","1",*a)