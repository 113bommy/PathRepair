import time
import collections

LOCAL = False
start_time = None
if __name__ == '__main__':
    if LOCAL:
        start_time = time.time()

    n, k = list(map(lambda x: int(x), input().split(' ')))
    poses = list(map(lambda x: int(x), input().split(' ')))
    q = collections.deque()
    s = set()

    for i in poses:
        if i not in s:
            if len(q) == k:
                removed = q.pop()
                s.remove(removed)
            q.appendleft(i)
            s.add(i)


    print(len(q))
    print(' '.join([str(i) for i in q]))

    if LOCAL:
        print("--- %s seconds ---" % (time.time() - start_time))
