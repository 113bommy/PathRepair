n,p=map(int,input().split())
root=round(p**(1/n))
for i in range(root,0,-1):
        if(p%(i**n)==0):
                print(i)
                break 