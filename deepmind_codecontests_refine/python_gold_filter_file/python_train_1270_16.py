T = int(input())
for i in range(T):
    n = int(input())
    lst = [int(w) for w in input().split()]
    if len(lst) < 2:
        print("-1")
    else:
        shortest = -2
        previous = {}
        for i in range(0, n):
            curr = lst[i]
            if curr not in previous:
                previous[curr] = i
            else:
                curr_len = i-previous[curr]
                if shortest > curr_len or shortest == -2:
                    shortest = curr_len
                previous[curr] = i # bo może być sytuacja że potem będzie krótszy podciąg z tą samą liczbą
        print(shortest+1) # +1 bo indeksowanie od 0 sie zaczyna, a to jest długość
