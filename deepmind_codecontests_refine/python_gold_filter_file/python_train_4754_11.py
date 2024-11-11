list1 = [int(x) for x in input().split()]
max_value = 0
for x in range(14):
   if list1[x] != 0:
      list2 = list1[:]
      #list2[x]=0
      for i in range(14):
         list2[i]+=list1[x]//14
      j= x+1
      for i in range (list1[x]%14):
         j%=14
         list2[j]+=1
         j+=1
      sum1 = 0
      list2[x]-=list1[x]
      for i in range (14):
         if list2[i]%2 == 0:
            sum1+=list2[i]
      max_value = max(max_value,sum1)

print (max_value)

