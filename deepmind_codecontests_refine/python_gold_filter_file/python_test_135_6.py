for _ in range(int(input())):
    n, k = (int(i) for i in input().split())
    array = sorted((int(i) for i in input().split()), reverse= True)
    
    score = 0
    index = 0
    for _ in range(k):
        
        if index <= n-2:
            score += (array[index+k] // array[index])
            index += 1
        else:
            break
        
    print(score+sum(array[index+k:]))