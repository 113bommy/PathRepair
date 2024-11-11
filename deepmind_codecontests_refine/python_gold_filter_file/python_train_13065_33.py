n, m = map(int, input().split())
c = 0
for i in range(n) :
    nums1 = [int(num) for num in input().split()]
    for i in range(m) :
        if nums1[2*i] == 1 or nums1[(2*i)+1] == 1 :
            c = c+1
print(c)
