


sum,limit = map(int,input().split())

def lowbit(k):
    count = 0
    for i in k[::-1]:
        if i == '1':
            return 2**count

        else:
            count+=1

actual = 0
max = 0
for i in range(1,limit+1):
    c = bin(i)[2:]

    if lowbit(c)>max:
         max = lowbit(c)
    actual+=lowbit(c)

if sum<=actual:
 ans = []
 count = 0
 for i in range(limit,0,-1):



      count+=lowbit(bin(i)[2:])
      # print(count)
      ans.append(i)
      if count > sum:

         count-=lowbit(bin(i)[2:])
         # print(count)
         ans.pop(-1)



 # print(count)
 print(len(ans))
 print(*ans)

else:
    print(-1)

