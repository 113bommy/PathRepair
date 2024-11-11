        
from string import ascii_lowercase


d = {letter:index for index, letter in enumerate(ascii_lowercase, start=1)}     
n,q=list(map(int,input().split()))  
s=list(input())
#dict= {'a':'1','b':'2','c':'3','d':'4','e':'5','f':'6','g':'7','h':'8':'i':'9','j':'10','k':'11','l':'12','m':'13','n':'14','o':'15','p':'16','q':'17','r':'18','s':'19','t':'20','u':'21','v':'22','w':'23','x':'24','y':'25','z':'26'}
s=[d[a] for a in s]
#print(s)
p=[0]*n
p[0]=s[0]
i=1
while(i<n):
    p[i]=p[i-1]+s[i]
    i+=1
       
while(q>0):
    q-=1
    l,r=list(map(int,input().split()))  
    print(p[r-1]-p[l-1]+s[l-1])