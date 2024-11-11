def main():
    import heapq
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n-1):
        if a[i] >= a[i+1]:
            break
    else:
        print(1)
        return

    h = []
    heapq.heapify(h)
    kind = 1
    length = 0
    d = dict()
    for i in a:
        if length >= i:
            while h:
                hh = -heapq.heappop(h)
                if hh > i:
                    d.pop(hh)
                else:
                    heapq.heappush(h, -hh)
                    break
            for j in range(i, 0, -1):
                if j not in d:
                    d[j] = 2
                    heapq.heappush(h, -j)
                    kind = max(kind, 2)
                    while h:
                        hh = -heapq.heappop(h)
                        if hh > j:
                            d.pop(hh)
                        else:
                            heapq.heappush(h, -hh)
                            break
                    break
                else:
                    if d[j] < kind:
                        d[j] += 1
                        while h:
                            hh = -heapq.heappop(h)
                            if hh > j:
                                d.pop(hh)
                            else:
                                heapq.heappush(h, -hh)
                                break
                        break
            else:
                d[i] += 1
                kind += 1
        length = i

    def value(kind):
        h = []
        heapq.heapify(h)
        length = 0
        d = dict()
        for i in a:
            if length >= i:
                while h:
                    hh = -heapq.heappop(h)
                    if hh > i:
                        d.pop(hh)
                    else:
                        heapq.heappush(h, -hh)
                        break
                for j in range(i, 0, -1):
                    if j not in d:
                        d[j] = 2
                        heapq.heappush(h, -j)
                        while h:
                            hh = -heapq.heappop(h)
                            if hh > j:
                                d.pop(hh)
                            else:
                                heapq.heappush(h, -hh)
                                break
                        break
                    else:
                        if d[j] < kind:
                            d[j] += 1
                            while h:
                                hh = -heapq.heappop(h)
                                if hh > j:
                                    d.pop(hh)
                                else:
                                    heapq.heappush(h, -hh)
                                    break
                            break
                else:
                    return False
            length = i
        return True

    def b_search(ok, ng, value):
        while abs(ok-ng) > 1:
            mid = (ok+ng)//2
            if value(mid):
                ok = mid
            else:
                ng = mid
        return ok

    print(b_search(kind, max(1, kind-30), value))


main()