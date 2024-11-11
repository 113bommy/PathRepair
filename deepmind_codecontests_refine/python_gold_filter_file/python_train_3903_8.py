
def luckyNumberList(lucky):
  for i in range(1,10):
    n=len(lucky)
    p=2**i ## help to find the iterations of inner loop
    for j in range(n-p,n):
      num1=lucky[j]*10+4
      num2=lucky[j]*10+7
      lucky.append(num1)
      lucky.append(num2)

  # return lucky.index(k)+1
# def luckyNumber(k)

n=int(input())
lucky=[4,7]
luckyNumberList(lucky)
# print(lucky)
print(lucky.index(n)+1)
