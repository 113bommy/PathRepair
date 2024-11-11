
def func(a,b):
    bin_a=bin(a)[2:]
    bin_b=bin(b)[2:]
    #print(a,b)
    max_len=len(bin_b)
    res1=[]
    b+=1
    for x in range(max_len):
        base=2**(x+1)
        #print(base)
        num=(a//base)*(base//2)+max(a%base-(base//2),0)
#         print(num)
#         print("--------")
        res1.append(num)
    
    res2=[]
    for x in range(max_len):
        base=2**(x+1)
        #print(base)
        num=(b//base)*(base//2)+max(b%base-(base//2),0)
#         print(num)
#         print("--------")
        res2.append(num)
    #print(res1,res2)
    final=[x2-x1 for x1,x2 in zip(res1,res2)]
    #print(final)
    max_num=max(final)
    print(b-a-max_num)

t = int(input())
while t > 0:
    t -= 1
    m, n = map(int, input().split())
    func(m, n)
