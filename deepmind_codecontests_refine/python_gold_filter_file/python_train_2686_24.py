p=int(input())
alist=list(map(int,input().split()))

fact_list=[1]
fact_inv_list=[1]
for i in range(1,p):
  fact=(fact_list[-1]*i)%p
  fact_list.append(fact)
  fact_inv_list.append(pow(fact,p-2,p))
def comb_mod(n,r):
  return fact_list[n]*fact_inv_list[r]*fact_inv_list[n-r]
  
answer_list=[0]*p
for i in range(p):
  a=alist[i]
  if a==1:
    #1-(x-i)^(p-1)
    coeff_list=[0]*p
    coeff_list[0]=1
    for j in range(p):
      coeff=comb_mod(p-1,j)*pow(-i,p-1-j,p)
      coeff_list[j]-=coeff
      coeff_list[j]%=p
      
    #print(i,coeff_list)
    for i in range(p):
      answer_list[i]+=coeff_list[i]
      answer_list[i]%=p
      
print(*answer_list)