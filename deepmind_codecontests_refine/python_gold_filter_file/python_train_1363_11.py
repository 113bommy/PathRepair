n, k = [int(i) for i in input().split()]
list1 = [int(i) for i in input().split()]
maxi = 0.0


count = k-1
for i in range(n - k + 1):

    s = sum(list1[i:i + k ])
   # print(list1[i:i + k ])
    maxi = max(maxi, s/k)

    num = k
    for j in range(i + k, min(2*k+i, n)):

        s += list1[j]
  #      print(list1[j])
        num +=1

        maxi = max(maxi, s/num )

print(maxi)
