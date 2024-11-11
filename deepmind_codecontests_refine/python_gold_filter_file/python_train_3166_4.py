# intervals and visited intervals have the same key
# which is the order in which intervals were queried

counter = 1
queries = int(input())
visited_intervals = [0] * (queries + 1)

intervals = {}

def get_interval():
    return tuple(map(int, input().split()))

def reset_search_data():
    global queries
    global visited_intervals
    del visited_intervals
    visited_intervals = [0] * queries

def solve():

    global counter
    global visited_intervals

    for _ in range (queries):
        query = get_interval()
        if query[0] == 1:
           intervals[counter] = query
           counter += 1
        elif query[0] == 2:
            q = []
            q.append(query[1])
            # start new search
            reset_search_data()
            while len(q) > 0:
                q_interval = q.pop(0)
                for index in intervals:
                    c = intervals[index][1]
                    d = intervals[index][2]
                    a = intervals[q_interval][1]
                    b = intervals[q_interval][2]
                    if c < a < d or c < b < d:
                        if visited_intervals[index] == 0:
                            #print ("TRUE", c, a , d, " ", c ,b ,d )
                            #print("marking ", index)
                            visited_intervals[index] = 1
                            #print ("visited", index)
                            q.append(index)
            if visited_intervals[query[2]] == 1:
                print ("YES")
            else:
                print ("NO")
solve()