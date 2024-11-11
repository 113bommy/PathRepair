'''
    Auther: ghoshashis545 Ashis Ghosh
    College: jalpaiguri Govt Enggineerin College
    Date:28/03/2020
'''
from math import ceil,sqrt,log,gcd
def ii():return int(input())
def si():return input()
def mi():return map(int,input().split())
def li():return list(mi())
def main():
    
    
    
    # for _ in range(ii()):
    n,k=mi()
    s=si()
    x=[0]*26
    for i in s:
        x[ord(i)-ord('A')]+=1
    ans=1e5+5
    for i in range(k):
        ans=min(ans,x[i])
    ans*=k
    for i in range(k,26):
        ans+=x[i]
    print(int(ans))
   
    
    
    
    
    
    
    
    
    
if __name__ =="__main__":
    main()