def solution(l1,l2,l3):
    limak,rade=0,0
    l1r,l2r,l3r=l1.copy(),l2.copy(),l3.copy()
    l2r.reverse()
    l3r.reverse()
    i=0
    t=0
    ans=0
    #print(l1,l2,l3)
    while i<len(l3):
        t+=l3[i]
        l2[i]-=t*l1[1]
        l2[i]=max(0,l2[i])
        limak+=l2[i]
        i+=1
    t=0
    i=0
    #print(l1r,l2r,l3r)
    while i<len(l3r):
        t+=l3r[i]
        l2r[i]-=t*l1r[1]
        #print(l2r)
        l2r[i]=max(0,l2r[i])
        rade+=l2r[i]
        i+=1
    if limak==rade:
        print("Tie")
    elif limak>rade:
        print("Limak")
    else:
        print("Radewoosh")






def answer():
    l1 = [int(x) for x in input().split()]
    l2 = [int(x) for x in input().split()]
    l3 = [int(x) for x in input().split()]
    solution(l1,l2,l3)
answer()