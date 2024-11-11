K=int(input())
R=K%50
L=K//50
a=[49+L]*50#50*L回掛かるモード
if R!=0:
  a=[49+L+50-R]*50
  a[0]+=1
  for i in range(50-R):
    a[i]-=51
print(50)
print(' '.join(map(str, a)))