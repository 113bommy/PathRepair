import sys

def is_possible(n, ratings_list):
    sorted_ratings_list = sorted(ratings_list, reverse=True)

    team1 = sorted_ratings_list[:n]
    #print(team1)
    team2 = sorted_ratings_list[n:]
    #print(team1[-1])
    if team1[-1] in team2:
        return "NO"
    else:
        return "YES"

def main():
    n = int(sys.stdin.readline().strip())
    ratings_list = list(map(int, sys.stdin.readline().rstrip('\n').split(' ')))
    print(is_possible(n, ratings_list))

if __name__ == '__main__':
    main()
