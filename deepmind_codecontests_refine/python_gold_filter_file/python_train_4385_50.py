# x != y
# t1 for stairs
# t2 for elevator
# t3 to open/close doors
# z as elevator starting floor, closed door

def solution(x, y, z, t1, t2, t3):
    elevatorTravelTime = t2 * abs(z - x) + t2 * abs(y - x) + 3 * t3
    stairsTime = t1 * abs(y - x)

    if elevatorTravelTime <= stairsTime:
        print('YES')
    else:
        print('NO')
def test():
    solution(5, 1, 4, 4, 2, 1)
    solution(1, 6, 6, 2, 1, 1)
    solution(4, 1, 7, 4, 1, 2)
    
if __name__ == '__main__':        
    x, y, z, t1, t2, t3 = map(int, input().strip().split(' '))

    solution(x, y, z, t1, t2, t3)
