def main():
    n = int(input())
    short = [int(fld) - 1 for fld in input().strip().split()]
    assert len(short) == n
    ans = [None] * n
    ans[0] = 0
    justreached = reached = {0}
    step = 0
    while len(reached) < n:
        step += 1
        new = set()
        for i in justreached:
            for j in (i-1, i+1, short[i]):
                if 0 <= j < n and j not in reached:
                    new.add(j)
                    ans[j] = step
        justreached = new
        reached |= new
    print(' '.join(map(str, ans)))
                
    

main()