def findTwoGroup(n): 
    s = n * (n + 1) / 2
    group1Sum = s / 2
  
    group1=[] 
    group2=[] 
    for i in range(n, 0, -1): 
        if (group1Sum - i >= 0) : 
            group1.append(i) 
            group1Sum -= i 
        else : 
            group2.append(i) 
    print(abs(sum(group1)-sum(group2)))
    group1.sort()
    print(len(group1),*group1)
n=int(input())
findTwoGroup(n)