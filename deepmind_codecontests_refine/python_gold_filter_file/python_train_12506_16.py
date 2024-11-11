tc=int(input())
for i in range(0,tc):
    num=int(input())
    q=input()
    tf=False
    for j in range(1,num):
        if int(q[:j]) < int(q[j:]):
            tf=True
            ans=j
        else:
            continue
    if tf:
        print("YES\n2")
        print(q[:ans]," ",q[ans:])
    else:
        print("NO")
