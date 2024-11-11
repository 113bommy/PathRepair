ai,ao,at,aj,al,As,az = map(int,input().split())

ans = (ai//2)*4 + ao*2 + (aj//2)*4 + (al//2)*4
if(ai>0)&(aj>0)&(al>0):
    ai -= 1
    aj -= 1
    al -= 1
    tmp = 6 + (ai//2)*4 + ao*2 + (aj//2)*4 + (al//2)*4
    ans = max(ans,tmp)
print(ans//2)