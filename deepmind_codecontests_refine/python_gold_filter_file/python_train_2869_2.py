n=int(input())
for i in range(n):
    l=input()
    if len(l)<11:
        print(l)
    else:
        print(l[0]+str(len(l)-2)+l[-1])