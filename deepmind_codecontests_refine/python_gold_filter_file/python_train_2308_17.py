# -*- coding: utf-8 -*-
"""
Created on Wed Jun 19 19:30:16 2019

@author: Hamadeh
"""

class cinn:
    def __init__(self):
        self.x=[]
    def cin(self,t=int):
        if(len(self.x)==0):
            a=input()
            self.x=a.split()
            self.x.reverse()
        return self.get(t)
    def get(self,t):
        return t(self.x.pop())
    def clist(self,n,t=int): #n is number of inputs, t is type to be casted
        l=[0]*n
        for i in range(n):
            l[i]=self.cin(t)
        return l
    def clist2(self,n,t1=int,t2=int,t3=int,tn=2):
        l=[0]*n
        for i in range(n):
            if(tn==2):
                a1=self.cin(t1)
                a2=self.cin(t2)
                l[i]=(a1,a2)
            elif (tn==3):
                a1=self.cin(t1)
                a2=self.cin(t2)
                a3=self.cin(t3)
                l[i]=(a1,a2,a3)
        return l
    def clist3(self,n,t1=int,t2=int,t3=int):
        return self.clist2(self,n,t1,t2,t3,3)
    def cout(self,i,ans=''):   
        if(ans==''):
            print("Case #"+str(i+1)+":", end=' ')
        else:
            print("Case #"+str(i+1)+":",ans)
    def printf(self,thing):
        print(thing,end='')
    def countlist(self,l,s=0,e=None):
        if(e==None):
            e=len(l)
        dic={}
        for el in range(s,e):
            if l[el] not in dic:
                dic[l[el]]=1
            else:
                dic[l[el]]+=1
        return dic
    def talk (self,x):
        print(x,flush=True)
    def dp1(self,k):
        L=[-1]*(k)
        return L
    def dp2(self,k,kk):
        L=[-1]*(k)
        for i in range(k):
            L[i]=[-1]*kk
        return L
    def isprime(self,n):
        if(n==1 or n==0):
            return False
        for i in range(2,int(n**0.5+1)):
            if(n%i==0):
                return False
        return True
    def factors(self,n):    
        from functools import reduce
        return set(reduce(list.__add__, 
                    ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
    def nthprime(self,n):
        #usable up to 10 thousand
        i=0
        s=2
        L=[]
        while(i<n):
            while(not self.isprime(s)):
                s+=1
            L.append(s)
            s+=1
            i+=1
        return L
    def matrixin(self,m,n,t=int):
        L=[]
        for i in range(m):
            p=self.clist(n,t)
            L.append(p)
        return L
    def seive(self,k):
        #1000000 tops
        n=k+1
        L=[True]*n
        L[1]=False
        L[0]=False
        for i in range(2,n):
            if(L[i]==True):
                for j in range(2*i,n,i):
                    L[j]=False
        return L
    def seiven(self,n,L):
        i=0
        for j in range(len(L)):
            if(L[j]==True):
                i+=1
            if(i==n):
                return j
    def matrixin2(self,m,t=int):
        L=[]
        for i in range(m):
            iny=self.cin(str)
            lsmall=[]
            for el in iny:
                lsmall.append(t(el))
            L.append(lsmall)
        return L
c=cinn()
x=c.cin()
y=c.cin()
z=c.cin()
d=c.cin()
L=[x,y,z]
L.sort()
mid=L[1]
right=L[2]
left=L[0]
s=0
if(right-mid<d):
   s+=d-(right-mid)
if(mid-left<d):
    s+=d-(mid-left)
print(s)