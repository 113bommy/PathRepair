import sys
n = int(input())
I = lambda : map(int,sys.stdin.readline().split())
for _ in range (n) :
    n , m = I()
    minn = float("inf")
    st = input()
    a1 = (m//3+1)*("RGB")
    a1 = a1[:m]
    a2 = (m//3+1)*("BRG")
    a2 = a2[:m]
    a3 = (m//3+1)*("GBR")
    a3 = a3[:m]
    #print(a2)
    for i in range (n-m+1) :
        c1 = 0 ; c2 = 0 ; c3 =0 ;
        for j in range (m) :
            if st[i+j] == a1[j] :
                pass
            else :
                c1+=1
            if st[i+j] == a2[j] :
                pass
            else :
                c2+=1
            if st[i+j] == a3[j] :
                pass
            else :
                c3+=1
        minn = min(minn , c1)
        minn = min(minn , c2)
        minn = min(minn , c3)
    print(minn)