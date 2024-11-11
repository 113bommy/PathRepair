
def main():
    n = int(input())
    vote = list(map(int, input().split()))
    total_e_vote = sum(vote)

    hyp = max(vote)
    while hyp:
        total_a_vote = 0
        for i in vote:
            total_a_vote += (hyp - i)
        
        if total_a_vote <= total_e_vote:
            hyp += 1
        else:
            print(hyp)
            break


if __name__ == "__main__":
    main()