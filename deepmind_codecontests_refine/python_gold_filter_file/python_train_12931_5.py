a,b = list(map(int,input().split()))
aa = input().split()
bb = input().split()
for _ in range(int(input())):
    i = int(input())-1
    print("{}{}".format(aa[i%a],bb[i%b]))
