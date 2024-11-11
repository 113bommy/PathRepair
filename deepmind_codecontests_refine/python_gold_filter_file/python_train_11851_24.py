n=int(input())
# Disadvantages of not reading qn properly in the beginning, all of them must be distinct
if n==3:
    print(2, 5 ,63)
elif n==4:
    print(2 ,5 ,20, 63)
elif n==5:
    print(2,5,20,30,63)
else:
    ans=[]
    k=0
    while len(ans)<n:
        ans.append(6*k+2)
        ans.append(6*k+3)
        ans.append(6*k+4)
        ans.append(6*k+6)
        k+=1
    # print(ans)
    ans=sorted(ans)[:n]
    # print(ans)
    nxt=6*(ans[-1]//6)
    if sum(ans)%6==2:
        ans.remove(8)
        ans.append(nxt+6)
    elif sum(ans)%6==3:
        ans.remove(9)
        ans.append(nxt+6)
    elif sum(ans)%6==5:
        ans.remove(9)
        ans.append(nxt+4)
    print(" ".join(list(map(str,ans))))
