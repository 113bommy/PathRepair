for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]

    distances = {}
    for ind, a_i in enumerate(a):
        if a_i not in distances:
            distances[a_i] = [ind, ind]
        else:
            distances[a_i] = [ind, max(ind - distances[a_i][0] - 1, distances[a_i][1])]

    # print(distances)

    for a_i in distances:
        distances[a_i][1] = max(len(a) - 1 - distances[a_i][0], distances[a_i][1])

    # print(distances)

    accepted_values = sorted(distances, key=lambda x: (distances[x][1], x))

    found_distances = {}
    for value in accepted_values:
        if distances[value][1] not in found_distances:
            found_distances[distances[value][1]] = value

    # print(found_distances)

    minimum = float('inf')
    start = -1
    ans = []
    for ind in range(n):
        if start == -1 and ind in found_distances:
            minimum = min(minimum, found_distances[ind])
            ans.append(minimum)
            start = ind
        elif start == -1 and ind not in found_distances:
            ans.append(-1)
        elif start >= 0 and ind in found_distances:
            minimum = min(minimum, found_distances[ind])
            ans.append(minimum)
            start = ind
        elif start >= 0 and ind not in found_distances:
            minimum = min(minimum, found_distances[start])
            ans.append(minimum)

    print(*ans)


    # pairs = tuple((value, distance) for distance, value in sorted(distances, key=lambda key: (distances[key][1], key)))

    # print(pairs)
