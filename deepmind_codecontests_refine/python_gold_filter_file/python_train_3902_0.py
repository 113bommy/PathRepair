n, m = map(int, input().split())
s1 = "#"*m
s2 = "."*(m-1)+'#'
s3 = "#"+"."*(m-1)
s = [s1,s2,s1,s3]
for i in range(n):
    print(s[i%4])
