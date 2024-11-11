

def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    T=I()
    M=60
    


    
    def pipo(x):
        cnt=0
        for i in range(M):
            if x==0:
                return cnt
            else:
                x=x//2
                cnt+=1
    

        
    
    for _ in range(T):
        N=I()
        A=LI()
        S=list(input())
        #後ろから見ていき，S=0の数だけで作れない数が(S=1の時に)出てきたらNG
        Vec=[]
        flag=1
        for i in range(N-1,-1,-1):
            #print(i,S[i]) 
            if S[i]=="0":
                if Vec==[]:
                    Vec.append((A[i],pipo(A[i])))
                else:
                    now=A[i]
                    p=pipo(A[i])
                    for v in Vec:
                        if v[1]==p:
                            now=now^v[0]
                            p=pipo(now)
                    if now!=0:
                        Vec.append((now,pipo(now)))
                        Vec.sort(reverse=True)
                            
                
            else:
                #print(Vec)
                now=A[i]
                for v in Vec:
                    if v[1]==pipo(now):
                        now=now^v[0]
                if now!=0:
                    flag=0

                    
                
        if flag:
            print(0)
        else:
            print(1)
            
            
        
        
        
        

main()
