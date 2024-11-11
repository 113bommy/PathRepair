n,c=[int(x) for x in input().split()]
times=[int(x) for x in input().split()]
times.reverse()
check=1
for i in range(len(times)-1):
    if times[i]-times[i+1]>c:
        print(i+1)
        check=0
        break
if check==1:
    print(len(times))