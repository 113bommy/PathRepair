S="012 345 678 036 147 258 048 246 "
A=[]
A.extend(list(map(int,input().split())) for i in range(3))
N=int(input())
for i in range(N):
  j=input()
  for l in range(3):
    for m in range(3):
      S=S.replace(str([9,l*3+m][A[l][m]==int(j)]),"")
print(["No","Yes"][S.find("  ")>-1])