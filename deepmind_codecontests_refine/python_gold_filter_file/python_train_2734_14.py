t = int(input())
while(t):
    t -= 1
    n = int(input())
    List = list(map(int,input().split()))
    sum_ = sum(List)
    if sum_ % 2 != 0:
        print('YES');continue
    else:
        count = 0
        for i in range(len(List)):
            x = 0
            x = sum_ - List[i]
            if x % 2== 0:
                for j in range(len(List)):
                    if List[j] % 2 != 0 and List[i] != List[j]:
                        print('YES');count += 1;break
            else:
                for k in range(len(List)):
                    if List[k] % 2 == 0 and List[i] != List[k]:
                        print('YES');count += 1;break
            if count > 0:
                break
        if count == 0:
            print('NO')
                     