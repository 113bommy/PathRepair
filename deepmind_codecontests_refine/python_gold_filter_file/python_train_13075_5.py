def get_min_replacement(a:str, b:str):
    minRep = len(a)
    minRepArr = []
    for i in range(len(b)-len(a)+1):
        repArr = []
        for j in range(len(a)):
            if a[j] != b[i+j]:
                repArr.append(j+1)
        if len(repArr) <= minRep:
            minRep = len(repArr)
            minRepArr = repArr
            
    return minRepArr

n,m = map(int,input().split())
s = str(input())
t = str(input())

minRepArr =  get_min_replacement(s,t)
print(len(minRepArr))
for i in range(len(minRepArr)):
    print(minRepArr[i], end =" ")
