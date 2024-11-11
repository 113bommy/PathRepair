def dd(s):
    return len(set(str(s)))==len(str(s))
if(__name__=='__main__'):
    l,r=map(int,input().split())
    ans=-1
    for i in range(l,r+1):
        if(dd(i)):
           ans=i
           break
    print(ans)
           
