n=int(input())
L=list(map(int,input().split()))
dic={}
for i in range(n):
    if(L[i] not in dic):
        dic[L[i]]=[i,0]
    else:
        if(dic[L[i]][1]==0):
            dic[L[i]][1]=i-dic[L[i]][0]
            dic[L[i]][0]=i
        elif(dic[L[i]][1]!=-1):
            if(i-dic[L[i]][0]==dic[L[i]][1]):
               dic[L[i]][0]=i
            else:
                dic[L[i]][1]=-1

count=0
for each in dic:
    if(dic[each][1]!=-1):
        count+=1
print(count)
for each in sorted(dic):
    if(dic[each][1]!=-1):
        print(each,dic[each][1])
            