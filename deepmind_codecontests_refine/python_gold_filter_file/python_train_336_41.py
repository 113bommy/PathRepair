a=int(input())
def modFact(n, p): 
    if n >= p: 
        return 0    
  
    result = 1
    for i in range(1, n + 1): 
        result = (result * i) % p  
  
    return result
ans=modFact(a,pow(10,9)+7)-pow(2,a-1,pow(10,9)+7)
if(ans<0):
    ans=pow(10,9)+7-abs(ans)
print(ans)