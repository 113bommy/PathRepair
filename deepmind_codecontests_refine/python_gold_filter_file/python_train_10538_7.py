#akash mandal: jalpaiguri government engineering college
#take a look on special cases: test cases

def ii(): return int(input())
def mii(): return map(int,input().split())
def lmii(): return list(mii())


def main():
    x,y,m=mii()
    a=lmii();b=lmii()
    ans1=ans2=-1
    for i in range(x):
        if a[i]%m!=0 and ans1==-1:
            ans1=i
    for i in range(y):
        if b[i]%m!=0 and ans2==-1:
            ans2=i
    print(ans2+ans1)
                
        
        
        
if __name__=="__main__": 
    main() 