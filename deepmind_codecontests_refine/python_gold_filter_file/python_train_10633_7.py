n,m=map(int,input().split())
lst=[];lst2=[]
for c in range(n):
    lst.append(list(map(int,input().split())))
for c in range(n):
    lst2.append(list(map(int,input().split())))
#print(lst,lst2)
for c in range(n):
    for r in range(len(lst[c])):
        p=0
        if lst[c][r]!=lst2[c][r]:
            a=c;b=r
            a+=1;b-=1
            while(a!=n and b!=-1 ):
                if lst2[a][b]==lst[c][r]:
                    p=1
                    break
                a+=1;b-=1
            if p==1:
                while a!=c and b!=r:
                    a-=1;b+=1
                    #print(c,r,a,b)
                    #swap(lst2[a][b],lst2[a+1][b-1])
                    lst2[a][b],lst2[a+1][b-1]=lst2[a+1][b-1],lst2[a][b]
            else:
                print("NO")
                exit(0)
            #print(lst2)
print("YES")