def ss(s1,s2):
    if(len(s1)<=len(s2)):
        return s1
    else :
        return s2


m,n=list(map(int,input().split(' ')))
di={}
for i in range (n) :
    s1,s2 =input().split(' ')
    di[s1]=ss(s1,s2)
    di[s2]=ss(s1,s2)
p=input().split(' ')
for i in p:
    print(di[i],end=' ')
print()