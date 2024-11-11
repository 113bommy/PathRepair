def run():
    ws = [i for i, j in enumerate(input(), 1) if j == "1"]
    m = int(input())
    q = [(-1, 0, 0, [])]
    while len(q) != 0:
        previous, need, index, lst = q.pop()
        if index == m:
            print("YES")
            print(' '.join(list(map(str, lst))))
            return
        for w in ws:
            if w > need and w != previous:
                q.append((w, w-need, index+1, lst+[w]))

    print("NO")
    return


run()
