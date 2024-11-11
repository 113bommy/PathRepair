import operator
n=int(input())
dict2={}
for i in range(0,n):
    s=input()
    s1=''.join(set(s))
    count=len(s1)
    if count==2:
        if s1 in dict2.keys():
            dict2[s1]+=len(s)
        elif s1[::-1] in dict2.keys():
            dict2[s1[::-1]]+=len(s)
        else:
            dict2[s1]=len(s)
            for a in dict2.keys():
                if a in s1 and (s1!=a):
                    dict2[s1]+=dict2[a]
    if count==1:
        for a in dict2.keys():
            if s1 in a and (s1!=a):
                dict2[a]+=len(s)
        if s1 in dict2.keys():
            dict2[s1]+=len(s)
        else:
            #print('hey')
            dict2[s1]=len(s)
    #print(s1,dict2[s1])
dict2['0']=0
maxsum=0
count2=2
for key,value in sorted(dict2.items(),key=operator.itemgetter(1),reverse=True):
    if len(key)==1:
        #print('hr',value)
        maxsum+=value
        count2-=1
    if count2==0:
        break
#print(maxsum)
a=max(maxsum,max(dict2.values()))
ans=str(a)

print(str(ans))
