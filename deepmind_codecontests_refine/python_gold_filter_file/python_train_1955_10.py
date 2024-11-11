n=int(input())
data=[[0]*50 for i in range(50)]

for i in range(n):
    s=input()
    l=len(s)
    num=0
    sho=0
    keta=1
    for i in range(l):
        if(s[l-i-1]!='.'):
            num+=keta*int(s[l-i-1])
            keta*=10
        else:
            sho=i
    #print(num,sho)
    two=-sho
    five=-sho
    for i in range(100):
        if(num%2==0):
            two+=1
            num//=2
        else:
            break
    for i in range(100):
        if(num%5==0):
            five+=1
            num//=5
        else:
            break
    #print(two,five)
    data[two+9][five+9]+=1


ans=0
for i in range(50):
    for j in range(50):
        jibun=data[i][j]
        if(jibun==0):
            continue
        aite=0
        for p in range(max(0,18-i),50):
            for q in range(max(0,18-j),50):
                aite+=data[p][q]
                if(p==i and j==q):
                    aite-=1
        ans+=jibun*aite
        #print(i-9,j-9,jibun,aite)

print(ans//2)