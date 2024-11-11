def ca():
    x,y,z,k=map(int,input().split())
    a=[int(i)for i in input().split()]
    b=[int(i)for i in input().split()]
    c=[int(i)for i in input().split()]
    c.sort(reverse=True)
    AB=[i+j for i in a for j in b]
    AB.sort(reverse=True)
    ans=[i+j for i in AB[:k]for j in c]
    ans.sort(reverse=True)
    for i in ans[:k]:
        print(i)
    exit()
print(ca())