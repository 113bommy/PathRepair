from bisect import bisect_left

def main():
    buf = input()
    buflist = buf.split()
    n = int(buflist[0])
    m = int(buflist[1])
    ta = int(buflist[2])
    tb = int(buflist[3])
    k = int(buflist[4])
    buf = input()
    buflist = buf.split()
    a = list(map(int, buflist))
    buf = input()
    buflist = buf.split()
    b = list(map(int, buflist))
    if k >= n or k >= m:
        print(-1) # cancel all
        return
    if bisect_left(b, a[0] + ta) == len(b):
        print(-1) # no flight from B to C
        return
    latest_arrival = b[bisect_left(b, a[0] + ta)] + tb
    for i in range(0, k+1):
        if bisect_left(b, a[i] + ta) + (k - i) >= len(b):
            print(-1) # no flight from B to C
            return
        arrival = b[bisect_left(b, a[i] + ta) + (k - i)] + tb
        if arrival > latest_arrival:
            latest_arrival = arrival
    print(latest_arrival)

if __name__ == '__main__':
    main()
