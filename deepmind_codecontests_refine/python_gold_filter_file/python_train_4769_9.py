import heapq


class PriorityQueue:
    def __init__(self):
        self.__heap = []
        self.__count = 0

    def empty(self) -> bool:
        return self.__count == 0

    def dequeue(self):
        if self.empty():
            raise Exception('empty')
        self.__count -= 1
        return heapq.heappop(self.__heap)

    def enqueue(self, v):
        self.__count += 1
        heapq.heappush(self.__heap, v)

    def __len__(self):
        return self.__count


def absolute_minima():
    Q = int(input())

    L, R = PriorityQueue(), PriorityQueue()
    sL, sR = 0, 0
    M = None
    B = 0
    N = 0

    for _ in range(Q):
        query = [int(s) for s in input().split()]

        if query[0] == 1:
            _, a, b = query
            B += b
            N += 1

            if M is None:
                M = a
            elif M < a:
                R.enqueue(a)
                sR += a
            else:
                L.enqueue(-a)
                sL += a

            while len(R)-len(L) > 1:
                L.enqueue(-M)
                sL += M

                M = R.dequeue()
                sR -= M

            while len(L) > len(R):
                R.enqueue(M)
                sR += M

                M = -L.dequeue()
                sL -= M

        else:
            s = - sL + sR + B
            if N % 2 == 0:
                s -= M
            print(M, s)


if __name__ == "__main__":
    absolute_minima()
