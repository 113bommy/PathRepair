# D. Binary String To Subsequences

for _ in range(int(input())):
    n = int(input())
    s = input()

    # Key ideas are from https://codeforces.com/contest/1399/submission/89096269
    
    # Increases with ones, decreases with zeroes
    # In other words, when positive, we have more ones; when negative - zeroes
    countr = 0
    # 
    segments = list()

    for ch in s:
        
        if ch == '1':
           countr += 1
        
        segments.append(countr)
        
        if ch == '0':
            countr -= 1
        
    num_of_segments = max(segments) - min(segments) + 1
    print(num_of_segments)

    min_segment_number = min(segments) - 1
    output = [x - min_segment_number for x in segments]
    print(*output)
