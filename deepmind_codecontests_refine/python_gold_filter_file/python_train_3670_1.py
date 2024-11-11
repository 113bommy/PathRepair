for _ in range(int(input())):
    n = int(input())
    arr1 = list(map(int, input().split(" ")))
    arr2 = list(map(int, input().split(" ")))
    res = "yes"

    if(sorted(arr1) != sorted(arr2)):
        print("no")
        continue
    
    if n%2 == 1 and arr1[n//2] != arr2[n//2]:
        print("no")
        continue

    pos_map = {}

    set1 = []
    set2 = []

    # for idx, i in enumerate(arr1):
    #     if i not in pos_map:
    #         pos_map[i] = set()
    #     pos_map[i].add(idx if idx< n//2 else (n-1)-idx)

    for idx, i in enumerate(arr1[:n//2]):
        set1.append([max(arr1[idx], arr1[(n-1)-idx]), min(arr1[idx], arr1[(n-1)-idx])])
        set2.append([max(arr2[idx], arr2[(n-1)-idx]), min(arr2[idx], arr2[(n-1)-idx])])

    if sorted(set1) == sorted(set2):
        print("yes")
    else:
        print("no")




        