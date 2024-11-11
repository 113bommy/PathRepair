dic={}
dic['0']=[]
dic['1']=[]
dic['2']=[2]
dic['3']=[3]
dic['4']=[3,2,2]
dic['5']=[5]
dic['6']=[5,3]
dic['7']=[7]
dic['8']=[7,2,2,2]
dic['9']=[7,3,3,2]
n=int(input())
s=input()
l=[]
for i in range(n):
    l.extend(dic[s[i]])
l=sorted(l,reverse=True)
for i in l:
    print(i,end='')
    
